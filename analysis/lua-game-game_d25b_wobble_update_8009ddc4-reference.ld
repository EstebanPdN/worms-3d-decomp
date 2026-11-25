/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25b_wobble_update_8009ddc4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
fn_80162bc8 = 0x80162bc8;
k2a_curve_eval_8009dfd4 = 0x8009dfd4;
s8_handle_800fc710 = 0x800fc710;
w3d_auto_80178c48 = 0x80178c48;
w3d_auto_80178d1c = 0x80178d1c;
w3d_auto_80178df0 = 0x80178df0;
w3d_auto_801797b4 = 0x801797b4;
w3d_cosf_802e86d4 = 0x802e86d4;
w3d_empty_80341584 = 0x80341584;
w3d_engine_get_context_80165254 = 0x80165254;
SECTIONS {
  .text.w3d_d25b_wobble_update_8009ddc4 0x8009ddc4 : { *(.text.w3d_d25b_wobble_update_8009ddc4) }
  .rodata 0x80380540 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
