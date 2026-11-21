/* THUNK.C -- redrawing the equipment panel, as a call of its own.
 */
#include "TAC.H"
#include "MAPDRAW.H"
#include "THUNK.H"

/* One call and nothing else, so it takes no frame. */
INT c_refresh_kit(void)
{
    /* Show the panel again; its one caller is planting a bug, which uses one up. */
    c_draw_kit_panel();
}
