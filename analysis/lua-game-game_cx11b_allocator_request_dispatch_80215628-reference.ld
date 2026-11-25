/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11b_allocator_request_dispatch_80215628)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_cx11b_allocator_request_dispatch_80215628 0x80215628 : { *(.text.w3d_cx11b_allocator_request_dispatch_80215628) }
  .sdata 0x804aba6c (NOLOAD) : {
    . = 0x0; allocator_804aba6c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
