/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40j_material_set_clear_80171624)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ef380 = 0x801ef380;
fn_802eee50 = 0x802eee50;
w3d_handle_storage_release = 0x802134fc;
w3d_s20_get_selected_80172088 = 0x80172088;
w3d_task_deferred_clear = 0x80210afc;
SECTIONS {
  .text.w3d_d40j_material_set_clear_80171624 0x80171624 : { *(.text.w3d_d40j_material_set_clear_80171624) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; lbl_804ab5fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
