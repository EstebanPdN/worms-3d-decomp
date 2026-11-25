/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f11b_control_initialize_checked_800fd8c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_801628b0 = 0x801628b0;
initial_80398140 = 0x80398140;
vtable_80410520 = 0x80410520;
SECTIONS {
  .text.f11b_control_initialize_checked_800fd8c8 0x800fd8c8 : { *(.text.f11b_control_initialize_checked_800fd8c8) }
  .sdata 0x804aaf64 (NOLOAD) : {
    . = 0x0; owner_804aaf64 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
