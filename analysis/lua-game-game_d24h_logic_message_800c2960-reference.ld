/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24h_logic_message_800c2960)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800c31f0 = 0x800c31f0;
fn_800c3cf4 = 0x800c3cf4;
fn_8015f5a0 = 0x8015f5a0;
fn_8015f65c = 0x8015f65c;
fn_8015fb34 = 0x8015fb34;
fn_8015fd1c = 0x8015fd1c;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_80165254 = 0x80165254;
fn_801797b4 = 0x801797b4;
fn_80341584 = 0x80341584;
lbl_8040db38 = 0x8040db38;
w3d_d24b_weapon_aim_start_800c2e44 = 0x800c2e44;
SECTIONS {
  .text.w3d_d24h_logic_message_800c2960 0x800c2960 : { *(.text.w3d_d24h_logic_message_800c2960) }
  .sdata 0x804ae6dc (NOLOAD) : {
    . = 0x0; lbl_804ae6dc = .;
    . = 0x10; lbl_804ae6ec = .;
    . = 0x20; lbl_804ae6fc = .;
    . = 0x48; lbl_804ae724 = .;
    . = 0x58; lbl_804ae734 = .;
    . = 0x70; lbl_804ae74c = .;
    . = 0x3078; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
