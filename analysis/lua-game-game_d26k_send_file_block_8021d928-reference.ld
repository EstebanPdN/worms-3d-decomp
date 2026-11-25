/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_send_file_block_8021d928)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
close_8020810c = 0x8020810c;
context_80165254 = 0x80165254;
finish_8021dd04 = 0x8021dd04;
key_8041a9f8 = 0x8041a9f8;
lock_801ef048 = 0x801ef048;
lookup_8020b680 = 0x8020b680;
object_80240994 = 0x80240994;
props_80240b84 = 0x80240b84;
send_8021e930 = 0x8021e930;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d26k_send_file_block_8021d928 0x8021d928 : { *(.text.w3d_d26k_send_file_block_8021d928) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
