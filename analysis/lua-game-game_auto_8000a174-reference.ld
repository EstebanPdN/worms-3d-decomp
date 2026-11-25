/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8000a174)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8000A758 = 0x8000a758;
fn_8000A7AC = 0x8000a7ac;
fn_8000B6BC = 0x8000b6bc;
fn_8000D004 = 0x8000d004;
SECTIONS {
  .text.w3d_auto_8000a174 0x8000a174 : { *(.text.w3d_auto_8000a174) }
  .text.w3d_auto_8000a204 0x8000a204 : { *(.text.w3d_auto_8000a204) }
  .text.w3d_auto_8000b2f8 0x8000b2f8 : { *(.text.w3d_auto_8000b2f8) }
  .text.w3d_auto_8000b864 0x8000b864 : { *(.text.w3d_auto_8000b864) }
  .text.w3d_auto_8000c0c0 0x8000c0c0 : { *(.text.w3d_auto_8000c0c0) }
  .text.w3d_auto_8000cf10 0x8000cf10 : { *(.text.w3d_auto_8000cf10) }
  .text.w3d_auto_8000cfe4 0x8000cfe4 : { *(.text.w3d_auto_8000cfe4) }
  .text.w3d_auto_8000d05c 0x8000d05c : { *(.text.w3d_auto_8000d05c) }
  .text.w3d_auto_8000d0a8 0x8000d0a8 : { *(.text.w3d_auto_8000d0a8) }
  .text.w3d_auto_8000d114 0x8000d114 : { *(.text.w3d_auto_8000d114) }
  .text.w3d_auto_8000d148 0x8000d148 : { *(.text.w3d_auto_8000d148) }
  .text.w3d_auto_8000d154 0x8000d154 : { *(.text.w3d_auto_8000d154) }
  .text.w3d_auto_8000d18c 0x8000d18c : { *(.text.w3d_auto_8000d18c) }
  .text.w3d_auto_8000d198 0x8000d198 : { *(.text.w3d_auto_8000d198) }
  .text.w3d_auto_8000d1d0 0x8000d1d0 : { *(.text.w3d_auto_8000d1d0) }
  .text.w3d_auto_8000d228 0x8000d228 : { *(.text.w3d_auto_8000d228) }
  .text.w3d_auto_8000d234 0x8000d234 : { *(.text.w3d_auto_8000d234) }
  .text.w3d_auto_8000d26c 0x8000d26c : { *(.text.w3d_auto_8000d26c) }
  .sdata 0x804aa554 (NOLOAD) : {
    . = 0x0; lbl_804AA554 = .;
    . = 0x38; lbl_804AA58C = .;
    . = 0x68; lbl_804AA5BC = .;
    . = 0x6c; lbl_804AA5C0 = .;
    . = 0x70; lbl_804AA5C4 = .;
    . = 0x74; lbl_804AA5C8 = .;
    . = 0x78; lbl_804AA5CC = .;
    . = 0x7c; lbl_804AA5D0 = .;
    . = 0x80; lbl_804AA5D4 = .;
    . = 0x84; lbl_804AA5D8 = .;
    . = 0x88; lbl_804AA5DC = .;
    . = 0x8c; lbl_804AA5E0 = .;
    . = 0x90; lbl_804AA5E4 = .;
    . = 0x94; lbl_804AA5E8 = .;
    . = 0x184; lbl_804AA6D8 = .;
    . = 0x22d4; lbl_804AC828 = .;
    . = 0x22d8; lbl_804AC82C = .;
    . = 0x22dc; lbl_804AC830 = .;
    . = 0x22e0; lbl_804AC834 = .;
    . = 0x22e4; lbl_804AC838 = .;
    . = 0x22e8; lbl_804AC83C = .;
    . = 0x22ec; lbl_804AC840 = .;
    . = 0x22f0; lbl_804AC844 = .;
    . = 0x22f4; lbl_804AC848 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
