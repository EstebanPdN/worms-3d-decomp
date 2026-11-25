/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_forward_global5_800e5cf0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800e5f98 = 0x800e5f98;
SECTIONS {
  .text.w3d_s20_forward_global5_800e5cf0 0x800e5cf0 : { *(.text.w3d_s20_forward_global5_800e5cf0) }
  .text.w3d_s20_store_and_dispatch_801a3190 0x801a3190 : { *(.text.w3d_s20_store_and_dispatch_801a3190) }
  .sdata 0x804aaecc (NOLOAD) : {
    . = 0x0; lbl_804aaecc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
