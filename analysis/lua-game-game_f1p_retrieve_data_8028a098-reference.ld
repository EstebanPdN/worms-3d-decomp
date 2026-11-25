/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_retrieve_data_8028a098)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fd488 = 0x800fd488;
fn_80208aac = 0x80208aac;
fn_8020b680 = 0x8020b680;
fn_802eee50 = 0x802eee50;
fn_802fb7ac = 0x802fb7ac;
message_803cfab4 = 0x803cfab4;
service_80418f78 = 0x80418f78;
SECTIONS {
  .text.w3d_retrieve_data_8028a098 0x8028a098 : { *(.text.w3d_retrieve_data_8028a098) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
