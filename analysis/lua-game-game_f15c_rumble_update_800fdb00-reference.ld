/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f15c_rumble_update_800fdb00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
option_80398148 = 0x80398148;
output_80160e34 = 0x80160e34;
paused_8015ccbc = 0x8015ccbc;
property_800fc230 = 0x800fc230;
stop_800fde38 = 0x800fde38;
update_800fdfec = 0x800fdfec;
SECTIONS {
  .text.f15c_rumble_update_800fdb00 0x800fdb00 : { *(.text.f15c_rumble_update_800fdb00) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; context_804aaabc = .;
    . = 0x6ccc; runtime_804b1788 = .;
    . = 0x6d34; service_804b17f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
