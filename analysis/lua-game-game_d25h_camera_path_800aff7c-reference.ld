/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__10CameraPathPcPCcif)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800b0474 = 0x800b0474;
fn_800fc1b0 = 0x800fc1b0;
fn_802efd7c = 0x802efd7c;
fn_80342a78 = 0x80342a78;
fn_80343744 = 0x80343744;
lbl_80382320 = 0x80382320;
SECTIONS {
  .text.__10CameraPathPcPCcif 0x800aff7c : { *(.text.__10CameraPathPcPCcif) }
  .rodata 0x80382334 : { *(.rodata) }
  .sdata 0x804aacb8 (NOLOAD) : {
    . = 0x0; lbl_804aacb8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
