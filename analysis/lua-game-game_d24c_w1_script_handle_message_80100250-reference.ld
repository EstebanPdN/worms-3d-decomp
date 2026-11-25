/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_w1_script_handle_message_80100250)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
base_8016293c = 0x8016293c;
call_801036f0 = 0x801036f0;
find_name_80161ffc = 0x80161ffc;
format_80103c44 = 0x80103c44;
id_equals_8015f65c = 0x8015f65c;
message_id_8015f5a0 = 0x8015f5a0;
start_80100490 = 0x80100490;
state_80102734 = 0x80102734;
stop_80100744 = 0x80100744;
strcpy = 0x802ef2fc;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
substitute_80103a5c = 0x80103a5c;
SECTIONS {
  .text.d24c_w1_script_handle_message_80100250 0x80100250 : { *(.text.d24c_w1_script_handle_message_80100250) }
  .sdata 0x804af16c (NOLOAD) : {
    . = 0x0; a_804af16c = .;
    . = 0x8; b_804af174 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
