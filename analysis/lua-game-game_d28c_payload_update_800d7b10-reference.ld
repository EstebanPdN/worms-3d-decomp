/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28c_payload_update_800d7b10)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
check_800eabb0 = 0x800eabb0;
desc_801797b4 = 0x801797b4;
distance_800ed860 = 0x800ed860;
empty_80341584 = 0x80341584;
land_800d8b4c = 0x800d8b4c;
move_800eac84 = 0x800eac84;
msg_id_8015f5a0 = 0x8015f5a0;
probe_800ea748 = 0x800ea748;
schedule_800d8ed8 = 0x800d8ed8;
timer_8006e71c = 0x8006e71c;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d28c_payload_update_800d7b10 0x800d7b10 : { *(.text.d28c_payload_update_800d7b10) }
  .rodata 0x803891e8 : { *(.rodata) }
  .sdata 0x804aeb00 (NOLOAD) : {
    . = 0x0; msgid_804aeb00 = .;
    . = 0x2e44; result_804b1944 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
