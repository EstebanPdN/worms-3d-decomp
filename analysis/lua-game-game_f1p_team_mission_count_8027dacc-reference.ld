/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_team_mission_count_8027dacc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
barracks_803ceaa0 = 0x803ceaa0;
current_803cea5c = 0x803cea5c;
fn_800fc1b0 = 0x800fc1b0;
fn_800fc2b0 = 0x800fc2b0;
fn_800fc43c = 0x800fc43c;
fn_801797b4 = 0x801797b4;
fn_8020bd38 = 0x8020bd38;
fn_8020c5c4 = 0x8020c5c4;
fn_8027be7c = 0x8027be7c;
fn_802ef234 = 0x802ef234;
fn_80341584 = 0x80341584;
fn_80341588 = 0x80341588;
retry_803cea38 = 0x803cea38;
SECTIONS {
  .text.w3d_team_mission_count_8027dacc 0x8027dacc : { *(.text.w3d_team_mission_count_8027dacc) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
