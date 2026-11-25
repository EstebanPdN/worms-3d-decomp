/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_connection_created_8021b1f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
key_8041a938 = 0x8041a938;
lookup_8020b680 = 0x8020b680;
msgid_8015f5a0 = 0x8015f5a0;
object_80240994 = 0x80240994;
release_header_8020bb2c = 0x8020bb2c;
send_8021e930 = 0x8021e930;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d26k_connection_created_8021b1f8 0x8021b1f8 : { *(.text.w3d_d26k_connection_created_8021b1f8) }
  .sdata 0x804b0704 (NOLOAD) : {
    . = 0x0; cache_804b0704 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
