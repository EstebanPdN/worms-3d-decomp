/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol11a_airstrike_target_800ef680)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_801613f0 = 0x801613f0;
camera_mode_8038be80 = 0x8038be80;
dispatch_8040db38 = 0x8040db38;
has_target_8038be6c = 0x8038be6c;
message_id_8015f5a0 = 0x8015f5a0;
payload_target_8038beac = 0x8038beac;
post_8016239c = 0x8016239c;
read_int_800fc230 = 0x800fc230;
read_vector_800fc2f0 = 0x800fc2f0;
target_point_8038be94 = 0x8038be94;
write_vector_800fc5dc = 0x800fc5dc;
SECTIONS {
  .text.sol11a_airstrike_target_800ef680 0x800ef680 : { *(.text.sol11a_airstrike_target_800ef680) }
  .sdata 0x804aefbc (NOLOAD) : {
    . = 0x0; cache_804aefbc = .;
    . = 0x58; cache_804af014 = .;
    . = 0x2798; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
