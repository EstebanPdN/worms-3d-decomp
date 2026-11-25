/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28c_payload_land_800d8b4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arrive_800d911c = 0x800d911c;
boundary_800d92a8 = 0x800d92a8;
cached_id_8015f5a0 = 0x8015f5a0;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
empty_80342a74 = 0x80342a74;
fn_800d8938 = 0x800d8938;
fn_8015fd1c = 0x8015fd1c;
query_800d93d0 = 0x800d93d0;
record_800d8fdc = 0x800d8fdc;
same_8015f65c = 0x8015f65c;
schedule_800d8ed8 = 0x800d8ed8;
span_800ecee8 = 0x800ecee8;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.d28c_payload_land_800d8b4c 0x800d8b4c : { *(.text.d28c_payload_land_800d8b4c) }
  .sdata 0x804aeb08 (NOLOAD) : {
    . = 0x0; id_804aeb08 = .;
    . = 0x8; id_804aeb10 = .;
    . = 0x10; id_804aeb18 = .;
    . = 0x18; id_804aeb20 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
