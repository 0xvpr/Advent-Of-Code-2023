#!/usr/bin/env python3

import os

if __name__ == "__main__":
    with open("input", "r") as f:
        for line in f.readlines():
            os.system(f'./a.exe "{line.strip()}"')
