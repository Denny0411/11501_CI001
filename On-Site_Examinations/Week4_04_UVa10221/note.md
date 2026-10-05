# UVa 10221

* 上機考時，不知道 1 min 是多少 degree
* 1°（度）= 60′（角分）= 3600″（角秒）
* 1 min = 1 / 60 deg

## Code v1

Before:

```cpp
else if (unit == "min")
{
    double deg = a / 720 * 360;
    arc = 2 * length * pi * (deg / 360);
    chord = length * sin( (deg / 2) / 360 * 2 * pi) * 2;
}
```

After:

```cpp
else if (unit == "min")
{
    double deg = a / 60;
    arc = 2 * length * pi * (deg / 360);
    chord = length * sin( (deg / 2) / 360 * 2 * pi) * 2;
}
```

Result: 範例測資正確，但 wrong answer。
* 未處理角度大於 $180^\circ$ 的情況。
* 若角度 $\theta$ 大於 $180^\circ$，需調整為 $360^\circ - \theta$。
* 我也不知道為什麼 :(