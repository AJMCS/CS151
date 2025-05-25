Questions:

1. What is/are the names of the base classes?
A: The name of the base class is Animal.

2. What is/are the names of the derived classes?
A: The names of the derived classes are Fox and Owl.

3. Does Animal have a parent class?
A: No,  it's the base class in this hierarchy.

4. Is the function showInfo overridden? Is makeNoise? Is sleep?
A: ShowInfo and makeNoise are overridden. The sleep function is not.

5. If the data member name in the Animal class were made protected (instead of private), would you need to use getters in the showInfo function of the child classes Fox and Owl?
A: You wouldn't need to use getters in the showInfo function because the child classes would have direct access to the name member.

6. What if the class data members were left private, but the base access modifiers to the Animal class in both child classes were made protected, would you need to use getters in the showInfo function of the child classes Fox and Owl?
A: Yes yo would still need to use getters in the showInfo function of the child classes. 