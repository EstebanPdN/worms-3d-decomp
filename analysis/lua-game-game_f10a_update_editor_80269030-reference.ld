/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f10a_update_editor_80269030)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
blend_803cb818 = 0x803cb818;
carry_803cb824 = 0x803cb824;
fn_80173f88 = 0x80173f88;
fn_8026b2c4 = 0x8026b2c4;
fn_8026b3f0 = 0x8026b3f0;
fn_8026c4dc = 0x8026c4dc;
fn_802b0668 = 0x802b0668;
lower_803cb820 = 0x803cb820;
upper_803cb81c = 0x803cb81c;
SECTIONS {
  .text.w3d_f10a_update_editor_80269030 0x80269030 : { *(.text.w3d_f10a_update_editor_80269030) }
  .sdata 0x804abb7c (NOLOAD) : {
    . = 0x0; world_804abb7c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
