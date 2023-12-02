# KnapSack

Our main target is to maximize profit. Two greedy approaches that we can use are:

1. **Maximizing Profit Alone:**
   - One approach is to prioritize objects with maximum profit. However, this approach doesn't consider the weight of the objects. It may not ensure maximum profit because an object with high profit might also have a large weight. In contrast, objects with lower profit but smaller weights combined could result in greater overall profit.

2. **Minimizing Weight Alone:**
   - Another approach is to start by putting objects with minimum weight, regardless of their profit. This might lead to a scenario where the sum of objects with smaller weights has less profit compared to a single object with a larger weight.

To balance both profit and weight, we should use an approach that considers both factors. We'll pick objects one by one based on their profit-to-weight ratio. This ratio ensures that the selected objects have high profit relative to their weight.

## Example:
- Object 1: Weight (w) = 4, Profit (p) = 32, Ratio = 8
- Object 2: Weight (w) = 8, Profit (p) = 32, Ratio = 4

In this example, the objects with a higher ratio have less weight and greater profit compared to other objects. Therefore, selecting objects based on this ratio helps us achieve the goal of maximizing profit while considering weight.
