#include "gtest/gtest.h"
#include "problem.h"
#include "equation.h"
#include "uniformmesh.h"
#include "variable.h"

TEST(UniformMeshTest, Accessors) {
    UniformMesh mesh(0.0, 2.0, 0.1, 0.0, 10.0, 0.1);

    ASSERT_DOUBLE_EQ(mesh.t_ini(), 0.0);
    ASSERT_DOUBLE_EQ(mesh.t_final(), 2.0);
    ASSERT_DOUBLE_EQ(mesh.dt(), 0.1);
    ASSERT_DOUBLE_EQ(mesh.x_min(), 0.0);
    ASSERT_DOUBLE_EQ(mesh.x_max(), 10.0);
    ASSERT_DOUBLE_EQ(mesh.dx(), 0.1);
    ASSERT_EQ(mesh.x_size(), 100);
    ASSERT_DOUBLE_EQ(mesh.x_i(5), 0.5);
}

TEST(VariableTest, Accessors) {
    UniformMesh mesh(0.0, 2.0, 0.1, 0.0, 10.0, 0.1);
    Variable variable(mesh, "test_variable");

    variable[0] = 1.0;
    variable[1] = 2.0;

    ASSERT_EQ(variable.x_size(), 100);
    ASSERT_DOUBLE_EQ(variable[0], 1.0);
    ASSERT_DOUBLE_EQ(variable[1], 2.0);
}

TEST(EquationTest, Compute) {
    double a = 0.5;
    Equation equation(a);

    UniformMesh mesh(0.0, 2.0, 0.1, 0.0, 10.0, 0.1);

    Variable u_n(mesh, "u_n");
    Variable u_np1(mesh, "u_np1");

    equation.compute(u_n, u_np1, mesh);

    ASSERT_DOUBLE_EQ(u_np1[0], u_n[0]);
    ASSERT_DOUBLE_EQ(u_np1[1], u_n[1] - a * (u_n[1] - u_n[0]));
}

TEST(ProblemTest, Solve) {
    double a = 0.5;
    Equation equation(a);

    UniformMesh mesh(0.0, 2.0, 0.1, 0.0, 10.0, 0.1);
    Problem problem(equation, &mesh);
    ASSERT_NO_THROW(problem.solve());
}
/*TEST(ProblemTest, SolveNullMesh) {
    double a = 0.5;
    Equation equation(a);
    UniformMesh* mesh = nullptr; // Use a null pointer
    // Create a Problem instance with a null mesh
    Problem problem(equation, mesh);

    // Test the solve method with a null mesh
    EXPECT_THROW(problem.solve(), std::invalid_argument);

    // Add more assertions as needed
}*/

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

