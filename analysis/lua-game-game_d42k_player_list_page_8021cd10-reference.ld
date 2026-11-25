/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d42k_player_list_page_8021cd10)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc2b0 = 0x800fc2b0;
fn_800fc330 = 0x800fc330;
fn_801ef174 = 0x801ef174;
fn_8020b680 = 0x8020b680;
fn_8021ed9c = 0x8021ed9c;
fn_8021edc4 = 0x8021edc4;
lbl_803b42c4 = 0x803b42c4;
lbl_803b42d4 = 0x803b42d4;
lbl_8041aa28 = 0x8041aa28;
lbl_8041aa38 = 0x8041aa38;
lbl_8041aa48 = 0x8041aa48;
strcmp = 0x802ef234;
SECTIONS {
  .text.w3d_d42k_player_list_page_8021cd10 0x8021cd10 : { *(.text.w3d_d42k_player_list_page_8021cd10) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
