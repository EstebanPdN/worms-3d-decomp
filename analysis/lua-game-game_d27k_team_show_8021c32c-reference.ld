/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27k_team_show_8021c32c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800a82f0 = 0x800a82f0;
fn_800fc1f0 = 0x800fc1f0;
fn_800fc7f8 = 0x800fc7f8;
fn_80129878 = 0x80129878;
fn_8015ccbc = 0x8015ccbc;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_80165254 = 0x80165254;
fn_8021c294 = 0x8021c294;
text_803b3efc = 0x803b3efc;
SECTIONS {
  .text.w3d_d27k_team_show_8021c32c 0x8021c32c : { *(.text.w3d_d27k_team_show_8021c32c) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; global_804aac54 = .;
    . = 0x2f4; global_804aaf48 = .;
    . = 0xe60; global_804abab4 = .;
    . = 0xe64; global_804abab8 = .;
    . = 0x5b38; global_804b078c = .;
    . = 0x6b00; global_804b1754 = .;
    . = 0x6b34; global_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
