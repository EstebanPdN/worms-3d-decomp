/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_team_panel_update_8021c48c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8003888c = 0x8003888c;
fn_800a82f0 = 0x800a82f0;
fn_800fc1f0 = 0x800fc1f0;
fn_800fc7f8 = 0x800fc7f8;
fn_80129878 = 0x80129878;
fn_801298cc = 0x801298cc;
fn_8015ccbc = 0x8015ccbc;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_80165254 = 0x80165254;
text_803b3efc = 0x803b3efc;
SECTIONS {
  .text.w3d_d26k_team_panel_update_8021c48c 0x8021c48c : { *(.text.w3d_d26k_team_panel_update_8021c48c) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; global_804aaabc = .;
    . = 0xff8; global_804abab4 = .;
    . = 0x5cd0; global_804b078c = .;
    . = 0x6c98; global_804b1754 = .;
    . = 0x6ccc; global_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
