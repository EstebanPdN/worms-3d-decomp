/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_make_message_800fb9e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801613f0 = 0x801613f0;
fn_801656bc = 0x801656bc;
fn_8017b8f4 = 0x8017b8f4;
fn_8019a2a8 = 0x8019a2a8;
fn_801b529c = 0x801b529c;
fn_8020fd2c = 0x8020fd2c;
fn_80308be8 = 0x80308be8;
lbl_803a54f4 = 0x803a54f4;
lbl_8040db38 = 0x8040db38;
lbl_80415320 = 0x80415320;
lbl_804552b0 = 0x804552b0;
lbl_80457014 = 0x80457014;
SECTIONS {
  .text.w3d_s20_make_message_800fb9e0 0x800fb9e0 : { *(.text.w3d_s20_make_message_800fb9e0) }
  .text.w3d_s20_unregister_801655b0 0x801655b0 : { *(.text.w3d_s20_unregister_801655b0) }
  .text.w3d_s20_select_entry_8016a570 0x8016a570 : { *(.text.w3d_s20_select_entry_8016a570) }
  .text.w3d_s20_unregister_8017b7e8 0x8017b7e8 : { *(.text.w3d_s20_unregister_8017b7e8) }
  .text.w3d_s20_set_record_flag_80199fa4 0x80199fa4 : { *(.text.w3d_s20_set_record_flag_80199fa4) }
  .text.w3d_s20_construct_pair_801bc394 0x801bc394 : { *(.text.w3d_s20_construct_pair_801bc394) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
