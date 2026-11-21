/* SOUND.C -- asking the driver for one of the module's sounds.
 */
#include "BUG.H"
#include "BOARD.H"

/* shared_include_start: ../../../../shared/c/PALETTE-RECORD.C -- generated */
/* PALETTE-RECORD.C -- c_set_palette_record, which sets one of the palette records.
 */

/* Hand palette record `record` to the resident palette setter, by address. */
void c_set_palette_record(INT record)
{
    drv_real_FUN_1000_00ca(shd_palette_records + record);
}
/* shared_include_end: ../../../../shared/c/PALETTE-RECORD.C */
