/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30c_input_flush_all_800f8018)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
array_80240bf8 = 0x80240bf8;
array_80240cc8 = 0x80240cc8;
array_80240d98 = 0x80240d98;
array_80240e68 = 0x80240e68;
array_80240f38 = 0x80240f38;
array_80241008 = 0x80241008;
array_802410d8 = 0x802410d8;
array_802411a8 = 0x802411a8;
array_80241278 = 0x80241278;
forward_8020b680 = 0x8020b680;
key_8041aa68 = 0x8041aa68;
key_8041aa78 = 0x8041aa78;
key_8041aa88 = 0x8041aa88;
key_8041aa98 = 0x8041aa98;
key_8041aaa8 = 0x8041aaa8;
key_8041aab8 = 0x8041aab8;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d30c_input_flush_all_800f8018 0x800f8018 : { *(.text.d30c_input_flush_all_800f8018) }
  .sdata 0x804abac0 (NOLOAD) : {
    . = 0x0; sink_804abac0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
