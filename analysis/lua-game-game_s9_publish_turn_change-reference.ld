/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_publish_turn_change_80155e24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800FC1F0 = 0x800fc1f0;
fn_800FC3B0 = 0x800fc3b0;
fn_800FC6DC = 0x800fc6dc;
fn_801555F8 = 0x801555f8;
fn_80155688 = 0x80155688;
fn_80155784 = 0x80155784;
fn_801558DC = 0x801558dc;
fn_80155C9C = 0x80155c9c;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80178C54 = 0x80178c54;
fn_8021C32C = 0x8021c32c;
fn_803426B4 = 0x803426b4;
lbl_803A27AC = 0x803a27ac;
lbl_803A27F0 = 0x803a27f0;
lbl_803A2A7C = 0x803a2a7c;
lbl_803A2A90 = 0x803a2a90;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.s9_publish_turn_change_80155e24 0x80155e24 : { *(.text.s9_publish_turn_change_80155e24) }
  .sdata 0x804abac0 (NOLOAD) : {
    . = 0x0; lbl_804ABAC0 = .;
    . = 0x4390; lbl_804AFE50 = .;
    . = 0x43f8; lbl_804AFEB8 = .;
    . = 0x5c94; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
