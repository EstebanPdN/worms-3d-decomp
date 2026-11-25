/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_service_call4_800fc110)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_service_call4_800fc110 0x800fc110 : { *(.text.w3d_s20_service_call4_800fc110) }
  .text.w3d_s20_service_call4_800fc160 0x800fc160 : { *(.text.w3d_s20_service_call4_800fc160) }
  .text.w3d_s20_service_call_800fc668 0x800fc668 : { *(.text.w3d_s20_service_call_800fc668) }
  .text.w3d_s20_service_call3_800fd440 0x800fd440 : { *(.text.w3d_s20_service_call3_800fd440) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
