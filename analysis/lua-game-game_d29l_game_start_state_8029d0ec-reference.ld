/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29l_game_start_state_8029d0ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
canAdd_803d0d54 = 0x803d0d54;
canStart_803d0ce0 = 0x803d0ce0;
finished_803d0d20 = 0x803d0d20;
fn_800fc1b0 = 0x800fc1b0;
fn_800fc230 = 0x800fc230;
fn_800fc2b0 = 0x800fc2b0;
fn_800fc43c = 0x800fc43c;
fn_800fc550 = 0x800fc550;
fn_801797b4 = 0x801797b4;
fn_8020c5c4 = 0x8020c5c4;
fn_80341584 = 0x80341584;
fn_80341588 = 0x80341588;
init_803d0bf0 = 0x803d0bf0;
local_803d0d04 = 0x803d0d04;
memset = 0x802eefe0;
strcmp = 0x802ef234;
text_803d0d44 = 0x803d0d44;
tipGen_803d0d30 = 0x803d0d30;
tipPlease_803d0d10 = 0x803d0d10;
tipStart_803d0cf0 = 0x803d0cf0;
SECTIONS {
  .text.d29l_game_start_state_8029d0ec 0x8029d0ec : { *(.text.d29l_game_start_state_8029d0ec) }
  .sdata 0x804abb7c (NOLOAD) : {
    . = 0x0; game_804abb7c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
