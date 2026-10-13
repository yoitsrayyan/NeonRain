<p align="center">
  <img src="assets/penguin.png" width="64" alt="Penguin mascot">
  <br>
  <img src="assets/neonrain-demo.gif" alt="Neon Rain demo">
</p>

<h1 align="center">Neon Rain</h1>

<p align="center">
  A lightweight C++ terminal animation inspired by falling Matrix code,
  with colorful true-color ANSI output.
</p>

## Requirements

- Linux or another ANSI-compatible terminal
- A terminal with 24-bit true-color support
- `g++`
- `make`

## Build

```bash
git clone https://github.com/YOUR_USERNAME/NeonRain.git
cd NeonRain
make
```

Run it locally:

```bash
./neonrain
```

Press `Ctrl+C` to stop it.

## Install system-wide

```bash
sudo make install
neonrain
```

The default installation path is `/usr/local/bin`. You can use a different
prefix without changing the Makefile:

```bash
make PREFIX="$HOME/.local" install
```

Make sure `"$HOME/.local/bin"` is in your `PATH`.

## Uninstall

For a system-wide installation:

```bash
sudo make uninstall
```

For a user-local installation:

```bash
make PREFIX="$HOME/.local" uninstall
```

## Project files

| File | Purpose |
| --- | --- |
| `src/NeonRainEffect.cpp` | The animation source code |
| `Makefile` | Build, install, uninstall, and clean commands |
| `assets/penguin.png` | Repository mascot |
| `assets/neonrain-demo.gif` | Recorded demo for the README |

## License

Use, modify, and share it freely. Add a license file if you want to publish
the project under a specific open-source license.
