function twoSum(nums: number[], target: number): number[] {
    const lookup = { [target - nums[0]]: 0 };
    for (let idx = 1; idx < nums.length; idx++) {
        const found = lookup[nums[idx]];
        if (found !== undefined) return [found, idx];
        lookup[target - nums[idx]] = idx;
    }
};
