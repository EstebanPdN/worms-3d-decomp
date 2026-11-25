/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30c_contact_query_800ea748)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
call_80126384 = 0x80126384;
clock_801264fc = 0x801264fc;
delta_800418ac = 0x800418ac;
done_80126524 = 0x80126524;
empty_80341584 = 0x80341584;
info_8003f240 = 0x8003f240;
memcpy_802eee50 = 0x802eee50;
release_802134fc = 0x802134fc;
resize_80213750 = 0x80213750;
sqrt_802e82c0 = 0x802e82c0;
step_801797b4 = 0x801797b4;
SECTIONS {
  .text.d30c_contact_query_800ea748 0x800ea748 : { *(.text.d30c_contact_query_800ea748) }
  .rodata 0x8038b3f0 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; id_804aa95e = .;
    . = 0x6; flag_804aa964 = .;
    . = 0x6e46; scale_804b17a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
