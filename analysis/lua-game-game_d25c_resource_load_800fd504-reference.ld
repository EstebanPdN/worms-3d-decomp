/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25c_resource_load_800fd504)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
strchr = 0x802ef198;
string_append_8020bf2c = 0x8020bf2c;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
string_truncate_8020c3a0 = 0x8020c3a0;
SECTIONS {
  .text.d25c_resource_load_800fd504 0x800fd504 : { *(.text.d25c_resource_load_800fd504) }
  .rodata 0x8039810c : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; services_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
