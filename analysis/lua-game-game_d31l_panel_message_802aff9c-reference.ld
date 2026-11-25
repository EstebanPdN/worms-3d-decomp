/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31l_panel_message_802aff9c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80069a50 = 0x80069a50;
fn_8010a8e0 = 0x8010a8e0;
fn_8010a8fc = 0x8010a8fc;
fn_8015f5a0 = 0x8015f5a0;
fn_8015f65c = 0x8015f65c;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_802b11d8 = 0x802b11d8;
fn_802b22b0 = 0x802b22b0;
fn_802b264c = 0x802b264c;
strcmp = 0x802ef234;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.d31l_panel_message_802aff9c 0x802aff9c : { *(.text.d31l_panel_message_802aff9c) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; flags_804aac54 = .;
    . = 0xef4; busy_804abb48 = .;
    . = 0x1014; input_804abc68 = .;
    . = 0x632c; msg_804b0f80 = .;
    . = 0x6334; msg_804b0f88 = .;
    . = 0x633c; msg_804b0f90 = .;
    . = 0x6344; msg_804b0f98 = .;
    . = 0x634c; msg_804b0fa0 = .;
    . = 0x6354; msg_804b0fa8 = .;
    . = 0x635c; msg_804b0fb0 = .;
    . = 0x6364; msg_804b0fb8 = .;
    . = 0x636c; msg_804b0fc0 = .;
    . = 0x6374; msg_804b0fc8 = .;
    . = 0x637c; msg_804b0fd0 = .;
    . = 0x6384; msg_804b0fd8 = .;
    . = 0x638c; msg_804b0fe0 = .;
    . = 0x6394; msg_804b0fe8 = .;
    . = 0x6b00; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
