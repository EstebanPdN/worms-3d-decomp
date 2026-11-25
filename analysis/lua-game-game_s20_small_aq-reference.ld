/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_trigger_effect_800e64e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc2b0 = 0x800fc2b0;
fn_800fd4c8 = 0x800fd4c8;
fn_800fd504 = 0x800fd504;
fn_8016b488 = 0x8016b488;
fn_80200a70 = 0x80200a70;
lbl_8038a62c = 0x8038a62c;
lbl_803a64ac = 0x803a64ac;
lbl_8040ef68 = 0x8040ef68;
lbl_80455980 = 0x80455980;
lbl_80455984 = 0x80455984;
SECTIONS {
  .text.w3d_s20_trigger_effect_800e64e8 0x800e64e8 : { *(.text.w3d_s20_trigger_effect_800e64e8) }
  .text.w3d_s20_check_then_count_8016b6d8 0x8016b6d8 : { *(.text.w3d_s20_check_then_count_8016b6d8) }
  .text.w3d_s20_init_global_object_8016f574 0x8016f574 : { *(.text.w3d_s20_init_global_object_8016f574) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
