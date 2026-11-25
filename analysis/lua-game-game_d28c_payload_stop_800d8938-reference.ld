/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28c_payload_stop_800d8938)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
base_800edbbc = 0x800edbbc;
ctx_80165254 = 0x80165254;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
fire_800d973c = 0x800d973c;
init_80126000 = 0x80126000;
msg_id_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
schedule_800d8ed8 = 0x800d8ed8;
span_800ecee8 = 0x800ecee8;
speed_800ecf54 = 0x800ecf54;
vt_8040db38 = 0x8040db38;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d28c_payload_stop_800d8938 0x800d8938 : { *(.text.d28c_payload_stop_800d8938) }
  .rodata 0x80389290 : { *(.rodata) }
  .sdata 0x804aeb00 (NOLOAD) : {
    . = 0x0; idC_804aeb00 = .;
    . = 0x50; idA_804aeb50 = .;
    . = 0x80; idB_804aeb80 = .;
    . = 0x2c54; heap_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
