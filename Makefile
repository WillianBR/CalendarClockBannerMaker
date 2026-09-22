# CalendarClockBannerMaker - GCC 10 / MinGW-w64 / TDM-GCC
# Usage: make DEBUG | make RELEASE | make clean

APP       := CalendarClockBannerMaker
CC        := gcc
SHELL     := cmd.exe
WINDRES   = windres
OBJCOPY   = objcopy
STRIP     = strip
ASTYLE    = astyle.exe
ZIP       = zip.exe
BUILD     ?= DEBUG

SRC          := $(APP).c
C_SOURCES    := $(wildcard *.c)
RC           := $(APP).rc
OUTDIR       := build/$(BUILD)
OBJ          := $(OUTDIR)/$(APP).o
RES          := $(OUTDIR)/$(APP)_res.o
EXE          := $(OUTDIR)/$(APP).exe
SHA256       := $(APP).sha256
HASH         := sha256sum.exe
PROCESS_NAME := $(APP).exe

CSTD      := -std=c11
WARN      := -Wall -Wextra -Wpedantic
DEFS      := -DUNICODE -D_UNICODE -D_WIN32_WINNT=0x0601
LIBS      := -lgdi32 -luser32 -lkernel32 -lshell32 -lcomdlg32 -lole32 -luuid
LDFLAGS   := -municode -mwindows

# ASTYLE_FLAGS := --style=allman --indent=spaces=4 --suffix=none
# 	--unpad-paren \
ASTYLE_FLAGS := \
	--style=allman \
	--indent=spaces=4 \
	--indent-switches \
	--pad-oper \
	--pad-comma \
	--pad-header \
    --pad-paren=none \
	--align-pointer=name \
	--break-one-line-headers \
	--convert-tabs \
	--line-between-members \
	--suffix=none

GIT_SHORT := $(strip $(shell git rev-parse --short HEAD 2>NUL || echo nogit))
GIT_DIRTY := $(strip $(shell git status --porcelain 2>NUL))
DIRTY_TAG := $(if $(GIT_DIRTY),-dirty,)
DBGFILE   := $(OUTDIR)/$(APP)_$(GIT_SHORT)$(DIRTY_TAG).dbg

ifeq ($(BUILD),RELEASE)
  CFLAGS := $(CSTD) $(WARN) $(DEFS) -O2 -g
else
  CFLAGS := $(CSTD) $(WARN) $(DEFS) -O0 -g3
endif

.PHONY: all DEBUG RELEASE clean info kill-running format

all: kill-running format $(EXE)

kill-running:
	@taskkill.exe /F /IM "$(PROCESS_NAME)" >NUL 2>&1 || exit /B 0

format:
	@where "$(ASTYLE)" >NUL 2>&1 || (echo ERROR: $(ASTYLE) not found in PATH. & exit /B 1)
	@if not "$(strip $(C_SOURCES))"=="" "$(ASTYLE)" $(ASTYLE_FLAGS) $(C_SOURCES)

DEBUG:
	$(MAKE) BUILD=DEBUG all

RELEASE:
	$(MAKE) BUILD=RELEASE all
	$(HASH) build/RELEASE/*.exe build/RELEASE/*.dbg > build/RELEASE/$(SHA256) 2>&1
	$(ZIP) -j "build/RELEASE/$(APP)_$(GIT_SHORT)$(DIRTY_TAG).zip" "build/RELEASE/$(APP).exe" "build/RELEASE/$(APP)_$(GIT_SHORT)$(DIRTY_TAG).dbg" "build/RELEASE/$(SHA256)"

$(OUTDIR):
	@if not exist "$(OUTDIR)" mkdir "$(OUTDIR)"

$(OBJ): $(SRC) resource.h | $(OUTDIR)
	$(CC) $(CFLAGS) -c "$<" -o "$@"

$(RES): $(RC) resource.h $(APP).ico | $(OUTDIR)
	$(WINDRES) -O coff "$<" "$@"

$(EXE): $(OBJ) $(RES)
	$(CC) $(OBJ) $(RES) -o "$@" $(LDFLAGS) $(LIBS)
	$(OBJCOPY) --only-keep-debug "$@" "$(DBGFILE)"
	$(STRIP) --strip-debug "$@"
	$(OBJCOPY) --add-gnu-debuglink="$(DBGFILE)" "$@"
	@echo Built: $(EXE)
	@echo Debug symbols: $(DBGFILE)

info:
	@echo BUILD=$(BUILD)
	@echo GIT_SHORT=$(GIT_SHORT)
	@echo DIRTY_TAG=$(DIRTY_TAG)

clean:
	@if exist build rmdir /S /Q build
