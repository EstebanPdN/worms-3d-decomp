/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28c_emitter_message_800e5304)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
alloc_80212fd4 = 0x80212fd4;
assign_800609ec = 0x800609ec;
base_8016293c = 0x8016293c;
cast_80342a78 = 0x80342a78;
empty_80343744 = 0x80343744;
fn_800e5698 = 0x800e5698;
free_802134fc = 0x802134fc;
load_800fd504 = 0x800fd504;
memcpy = 0x802eee50;
name_80179170 = 0x80179170;
same_8015f65c = 0x8015f65c;
spawn_800e5da0 = 0x800e5da0;
start_800e6390 = 0x800e6390;
strcmp_802ef234 = 0x802ef234;
string_assign_8020bd38 = 0x8020bd38;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
string_release_header_8020bb2c = 0x8020bb2c;
teams_8043bb64 = 0x8043bb64;
text_8010a8fc = 0x8010a8fc;
trigger_800e64e8 = 0x800e64e8;
update_80178d28 = 0x80178d28;
SECTIONS {
  .text.d28c_emitter_message_800e5304 0x800e5304 : { *(.text.d28c_emitter_message_800e5304) }
  .rodata 0x8038a4b4 : { *(.rodata) }
  .sdata 0x804aedb4 (NOLOAD) : {
    . = 0x0; id_804aedb4 = .;
    . = 0x8; id_804aedbc = .;
    . = 0x10; id_804aedc4 = .;
    . = 0x28; id_804aeddc = .;
    . = 0x30; id_804aede4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
