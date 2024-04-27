# BDIC COMP3036 Hackathon Guide: MPI Monte Carlo π Estimation
### Nima Afraz 2024

Welcome to the Monte Carlo π Estimation hackathon! In this event, participants will implement and optimize a parallel Monte Carlo simulation to estimate the value of π using the MPI (Message Passing Interface) framework. The goal is to achieve the most accurate estimation with the best performance.

## How to Participate

### 1. Understand the Problem

- **Objective**: Estimate the value of π using the Monte Carlo method using parallel processing.
- **Approach**: Generate random points in a square and count how many fall within a quarter circle. The ratio of points inside the circle to the total points gives an estimation of π/4.
- **Monte Carlo Method**:
    - Generate random points within a square with side length 1.
    - Determine if each point falls within a quarter circle with radius 1.
    - Estimate π as four times the ratio of points inside the circle to the total points.

### 2. Implement the Code

- **Language**: C programming language.
- **MPI Framework**: Use MPI for parallelization.
- **Provided Code**: A template code is provided with essential MPI initialization and estimation logic. Participants should fill in the missing parts.

### 3. Fill in the Missing Parts

- **Sync Timing**: Ensure all processes start timing at the same moment.
- **Distribute Workload**: Distribute the workload evenly among processes.
- **Gather Results**: Gather the results from all processes onto the root process.
- **Calculate Final Result**: Compute the final estimation of π on the root process.

### 4. Optimize for Performance

- Implement optimizations to minimize execution time.
- Consider load balancing and efficient use of MPI communication (use of correct communication methods).
- Test with different numbers of MPI processes (between 1-4 due to Beckett4 Limitation) to find the optimal configuration.

### 5. Submit Your Results

- Submit your results on [http://bdic.pythonanywhere.com/](http://bdic.pythonanywhere.com/).
- Ensure your submission includes:
    - Nickname(or Student Number)
    - Error percentage compared to the true value of π.
    - Total execution time in nanoseconds.
    - Memory usage in kilobytes.

### 6. Judging Criteria

- **Accuracy**: The lower the error rate, the better.
- **Performance**: Faster execution times are preferred.
- **Memory Usage**: Minimize memory consumption.
- **Leaderbard Ranking** The leaderboard uses a combined metric to rank the submissions.
- **Winner Verification** The winner will need to show the results they got on their terminal along with the code.
- **Bonus Marks**: The winner will receive a 5% bonus mark of the final grade.

### 7. Tiebreaker

- In case of equal results (Unlikely), a raffle will be conducted to determine the winner.

### 8. Good Luck and Have Fun!

- Enjoy the challenge of optimizing your code and competing against your peers.
- Feel free to collaborate, share insights, and learn from each other.

Best of luck to all participants!
