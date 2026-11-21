#!/bin/bash
#
# Run MSC 5.1's SETUP /L in a windowed DOSBox to build the combined libraries
# (LLIBCE.LIB and the rest), which are on no distribution disk: SETUP builds
# them from the component libraries in the lib directory.
#
# The batch file is written into the toolchain root, since DOSBox mounts the
# directory of the program it is given as C:; hence the C:\msc51\... paths.
#
# Interactive.
#
set -e

REPO_ROOT="$(cd "$(dirname "$0")/../.." && pwd)"

# Read the value out rather than sourcing .env.
env_value() {
    [ -f "$REPO_ROOT/.env" ] || return
    sed -n "s/^$1=//p" "$REPO_ROOT/.env" | tail -1 | tr -d '"\r'
}

DOS_DIR="${DOS_TOOLCHAIN_DIR:-$(env_value DOS_TOOLCHAIN_DIR)}"
[ "$DOS_DIR" ] || { echo "set DOS_TOOLCHAIN_DIR in .env"; exit 1; }
CONF="$REPO_ROOT/scripts/interop/toolchain.conf"

[ -d "$DOS_DIR/msc51/bin" ] || { echo "no msc51 tree under $DOS_DIR"; exit 1; }
[ -f "$CONF" ] || { echo "missing $CONF"; exit 1; }
which dosbox > /dev/null || { echo "dosbox not installed"; exit 1; }

BAT="$DOS_DIR/setup$$.bat"
trap 'rm -f "$BAT"' EXIT

cat > "$BAT" <<'EOF'
set PATH=Z:\;C:\msc51\bin
c:
cd \msc51\bin
echo ---------------------------------------------------------------
echo  SETUP /L  -- build the combined libraries
echo.
echo  Answer the prompts as follows:
echo.
echo    Operating environment ...... OS/2 Real Mode and DOS  (not Protected)
echo    Use default library names .. YES
echo    Memory models .............. all four: S, M, C, L
echo    Floating point ............. emulator, and 8087 as well
echo    Include GRAPHICS.LIB ....... NO
echo    Component library source ... C:\MSC51\LIB
echo    Combined library target .... C:\MSC51\LIB
echo    Delete component libraries . NO
echo.
echo  Type EXIT when SETUP finishes, to close DOSBox.
echo ---------------------------------------------------------------
SETUP /L
EOF

dosbox -conf "$CONF" "$BAT"

echo
echo "Combined libraries in $DOS_DIR/msc51/lib:"
ls -1 "$DOS_DIR/msc51/lib" | grep -iE '^[smcl]libc[e7a]\.lib$' || echo "  (none built)"
