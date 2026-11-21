/* PALETTE-RECORD.C -- c_set_palette_record, which sets one of the palette records.
 */

/* Hand palette record `record` to the resident palette setter, by address. */
void c_set_palette_record(INT record)
{
    drv_real_FUN_1000_00ca(shd_palette_records + record);
}
