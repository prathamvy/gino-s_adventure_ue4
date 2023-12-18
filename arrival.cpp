using System.Collections;
using System.Collections.Generic; using UnityEngine;
using UnityEngine.InputSystem;
public class ArrivalMovement : MonoBehaviour
{
[SerializeField] float runSpeed = 10f; Vector2 moveInput;
Rigidbody2D myRigidBody;

void Start()
{
myRigidBody = GetComponent<Rigidbody2D>();
}

void Update()
{
Run();
}
void Run()
{
Vector2 playerVelocity = new Vector2(moveInput.x * runSpeed, myRigidBody.velocity.y);
myRigidBody.velocity = playerVelocity;
}
void OnMove(InputValue value){ moveInput = value.Get<Vector2>(); Debug.Log(moveInput);
}
}
