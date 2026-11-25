/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_worm_message_bounce_801535cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
apply_80153f80 = 0x80153f80;
clock_801264fc = 0x801264fc;
finish_80126524 = 0x80126524;
hasEntity_80153a1c = 0x80153a1c;
log_80022e20 = 0x80022e20;
logic_entity_803a0e2c = 0x803a0e2c;
lookup_8003f240 = 0x8003f240;
msg_id_8015f5a0 = 0x8015f5a0;
position_801262c0 = 0x801262c0;
post_8016239c = 0x8016239c;
run_80126334 = 0x80126334;
sender_801190d0 = 0x801190d0;
sqrt_802e82c0 = 0x802e82c0;
target_message_801190b4 = 0x801190b4;
type_80361860 = 0x80361860;
type_803618f0 = 0x803618f0;
SECTIONS {
  .text.d27d_worm_message_bounce_801535cc 0x801535cc : { *(.text.d27d_worm_message_bounce_801535cc) }
  .rodata 0x803a1b64 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; kind_804aa95e = .;
    . = 0x53e2; cache_804afd40 = .;
    . = 0x6df6; heap_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
