/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_801c2654)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efd34 = 0x801efd34;
fn_801efd98 = 0x801efd98;
fn_801efdfc = 0x801efdfc;
fn_801efec4 = 0x801efec4;
fn_801f23bc = 0x801f23bc;
lbl_803ac764 = 0x803ac764;
lbl_803ac768 = 0x803ac768;
lbl_803ac76c = 0x803ac76c;
lbl_803ac778 = 0x803ac778;
lbl_803ac784 = 0x803ac784;
lbl_803ac790 = 0x803ac790;
lbl_803ac798 = 0x803ac798;
lbl_803ac7a0 = 0x803ac7a0;
lbl_8045d3e0 = 0x8045d3e0;
lbl_8045d3f4 = 0x8045d3f4;
lbl_8045d408 = 0x8045d408;
lbl_8045d41c = 0x8045d41c;
lbl_8045d430 = 0x8045d430;
lbl_8045d444 = 0x8045d444;
lbl_8045d458 = 0x8045d458;
lbl_8045d46c = 0x8045d46c;
lbl_8045e2b4 = 0x8045e2b4;
lbl_8045ed1c = 0x8045ed1c;
lbl_8045ed34 = 0x8045ed34;
lbl_8045ed4c = 0x8045ed4c;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_801c2654 0x801c2654 : { *(.text.w3d_s10_register_properties_801c2654) }
  .sdata 0x804b0464 (NOLOAD) : {
    . = 0x0; lbl_804b0464 = .;
    . = 0x4; lbl_804b0468 = .;
    . = 0x8; lbl_804b046c = .;
    . = 0xc; lbl_804b0470 = .;
    . = 0x10; lbl_804b0474 = .;
    . = 0x14; lbl_804b0478 = .;
    . = 0x18; lbl_804b047c = .;
    . = 0x1c; lbl_804b0480 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
