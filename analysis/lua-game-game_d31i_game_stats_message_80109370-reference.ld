/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31i_game_stats_message_80109370)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
a_80109bc4 = 0x80109bc4;
add_80109ab8 = 0x80109ab8;
append_8010a01c = 0x8010a01c;
b_80109bb4 = 0x80109bb4;
base_8016293c = 0x8016293c;
c_80109b0c = 0x80109b0c;
clear_80109ae4 = 0x80109ae4;
eq_8015f65c = 0x8015f65c;
expand_80109604 = 0x80109604;
flush_80109bec = 0x80109bec;
get_800a830c = 0x800a830c;
leave_8010a4ac = 0x8010a4ac;
read_text_800fc2b0 = 0x800fc2b0;
s_80399c08 = 0x80399c08;
start_8010a0f0 = 0x8010a0f0;
tally_80109b1c = 0x80109b1c;
SECTIONS {
  .text.d31i_game_stats_message_80109370 0x80109370 : { *(.text.d31i_game_stats_message_80109370) }
  .sdata 0x804af238 (NOLOAD) : {
    . = 0x0; id_804af238 = .;
    . = 0x8; id_804af240 = .;
    . = 0x10; id_804af248 = .;
    . = 0x18; id_804af250 = .;
    . = 0x20; id_804af258 = .;
    . = 0x28; id_804af260 = .;
    . = 0x30; id_804af268 = .;
    . = 0x38; id_804af270 = .;
    . = 0x40; id_804af278 = .;
    . = 0x48; id_804af280 = .;
    . = 0x50; id_804af288 = .;
    . = 0x58; id_804af290 = .;
    . = 0x60; id_804af298 = .;
    . = 0x68; id_804af2a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
