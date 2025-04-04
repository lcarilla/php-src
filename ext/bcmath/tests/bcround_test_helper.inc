<?php

function printResult (array $cases, RoundingMode $mode)
{
    foreach ($cases as [$num, $precision]) {
        echo str_pad("[{$num}, {$precision}]", 17, ' ', STR_PAD_LEFT), " => ", bcround($num, $precision, $mode), "\n";
    }
    echo "\n";
}

function run_round_test(RoundingMode $mode)
{
    $non_boundary_value_cases = [
        ['1.1', 0],
        ['1.2', 0],
        ['1.3', 0],
        ['1.4', 0],
        ['1.6', 0],
        ['1.7', 0],
        ['1.8', 0],
        ['1.9', 0],
        ['-1.1', 0],
        ['-1.2', 0],
        ['-1.3', 0],
        ['-1.4', 0],
        ['-1.6', 0],
        ['-1.7', 0],
        ['-1.8', 0],
        ['-1.9', 0],
    ];

    $minus_precision_cases = [
        ['0', -3],
        ['0.01', -3],
        ['-0.01', -3],
        ['50', -2],
        ['-50', -2],
        ['1230', -1],
        ['1235', -1],
        ['-1230', -1],
        ['-1235', -1],
        ['3400.0000', -2],
        ['3400.0001', -2],
        ['3450.0000', -2],
        ['3450.0001', -2],
        ['-3400.0000', -2],
        ['-3400.0001', -2],
        ['-3450.0000', -2],
        ['-3450.0001', -2],
    ];

    $zero_precision_cases = [
        ['1235', 0],
        ['1235.0', 0],
        ['1235.000001', 0],
        ['1235.5', 0],
        ['1235.500001', 0],
        ['-1235', 0],
        ['-1235.0', 0],
        ['-1235.000001', 0],
        ['-1235.5', 0],
        ['-1235.500001', 0],
        ['0.0001', 0],
        ['0.5', 0],
        ['0.5000', 0],
        ['0.5001', 0],
        ['-0.0001', 0],
        ['-0.5', 0],
        ['-0.5000', 0],
        ['-0.5001', 0],
    ];

    $plus_precision_cases = [
        ['28.40', 1],
        ['28.4000001', 1],
        ['28.45', 1],
        ['28.4500001', 1],
        ['-28.40', 1],
        ['-28.4000001', 1],
        ['-28.45', 1],
        ['-28.4500001', 1],
        ['153.90', 1],
        ['153.9000001', 1],
        ['153.95', 1],
        ['153.9500001', 1],
        ['-153.90', 1],
        ['-153.9000001', 1],
        ['-153.95', 1],
        ['-153.9500001', 1],
        ['0.000001', 3],
        ['0.0005', 3],
        ['0.000500', 3],
        ['0.000501', 3],
        ['-0.000001', 3],
        ['-0.0005', 3],
        ['-0.000500', 3],
        ['-0.000501', 3],
    ];

    echo "========== non-boundary value ==========\n";
    printResult($non_boundary_value_cases, $mode);

    echo "========== minus precision ==========\n";
    printResult($minus_precision_cases, $mode);

    echo "========== zero precision ==========\n";
    printResult($zero_precision_cases, $mode);

    echo "========== plus precision ==========\n";
    printResult($plus_precision_cases, $mode);
}
