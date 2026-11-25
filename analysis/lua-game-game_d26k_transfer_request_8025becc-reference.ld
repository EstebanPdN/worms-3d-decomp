/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_transfer_request_8025becc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
context_80165254 = 0x80165254;
key_8041a9d8 = 0x8041a9d8;
key_8041aa18 = 0x8041aa18;
lookup_8020b680 = 0x8020b680;
open_8021d498 = 0x8021d498;
release_header_8020bb2c = 0x8020bb2c;
send_8021e930 = 0x8021e930;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d26k_transfer_request_8025becc 0x8025becc : { *(.text.w3d_d26k_transfer_request_8025becc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
