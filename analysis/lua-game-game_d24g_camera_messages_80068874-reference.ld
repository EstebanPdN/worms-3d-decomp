/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_camera_messages_80068874)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
aim_800697ac = 0x800697ac;
base_8015fb34 = 0x8015fb34;
id_equals_8015f65c = 0x8015f65c;
read_800fc230 = 0x800fc230;
s_8037a858 = 0x8037a858;
set_shot_80069630 = 0x80069630;
start_80068a14 = 0x80068a14;
stop_80069430 = 0x80069430;
update_8006947c = 0x8006947c;
SECTIONS {
  .text.w3d_d24g_camera_messages_80068874 0x80068874 : { *(.text.w3d_d24g_camera_messages_80068874) }
  .sdata 0x804ad638 (NOLOAD) : {
    . = 0x0; c_804ad638 = .;
    . = 0x18; c_804ad650 = .;
    . = 0x20; c_804ad658 = .;
    . = 0x28; c_804ad660 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
