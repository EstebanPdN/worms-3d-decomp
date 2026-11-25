/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27k_transfer_reply_8025afc4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
context_80165254 = 0x80165254;
crc_8021d5c4 = 0x8021d5c4;
field_80240700 = 0x80240700;
find_8025d588 = 0x8025d588;
finish_8021dd04 = 0x8021dd04;
key_8041a9e8 = 0x8041a9e8;
lookup_8020b680 = 0x8020b680;
object_80240994 = 0x80240994;
props_80240b84 = 0x80240b84;
refill_802080a0 = 0x802080a0;
release_header_8020bb2c = 0x8020bb2c;
send_8021e930 = 0x8021e930;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d27k_transfer_reply_8025afc4 0x8025afc4 : { *(.text.w3d_d27k_transfer_reply_8025afc4) }
  .sdata 0x804abb1c (NOLOAD) : {
    . = 0x0; global_804abb1c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
