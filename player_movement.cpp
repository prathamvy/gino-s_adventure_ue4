using System.Collections;
using System.Collections.Generic; 
using UnityEngine;
using UnityEngine.InputSystem;

public class Movement : MonoBehaviour
{
[SerializeField] float runSpeed = 10f; [SerializeField] float jumpSpeed = 5f;


Vector2 moveInput; Rigidbody2D myRigidBody; Animator myAnimator;
CapsuleCollider2D myCapsuleCollider;

bool isAlive = true;
// Start is called before the first frame update void Start()
{
myRigidBody = GetComponent<Rigidbody2D>(); myAnimator = GetComponent<Animator>();
myCapsuleCollider = GetComponent<CapsuleCollider2D>();
}

// Update is called once per frame void Update()
{
if (!isAlive) { return; } Run();
FlipGino(); GinoDied();
}


void OnMove(InputValue value)
{
if (!isAlive) { return; } moveInput = value.Get<Vector2>(); Debug.Log(moveInput);
}


void Run()
 
{
Vector2 playerVelocity = new Vector2(moveInput.x * runSpeed,
myRigidBody.velocity.y);
myRigidBody.velocity = playerVelocity;

bool playerHasHorizontalSpeed = Mathf.Abs(myRigidBody.velocity.x) > Mathf.Epsilon;
myAnimator.SetBool("isRunning", playerHasHorizontalSpeed);

}
void FlipGino()
{
bool playerHasHorizontalSpeed = Mathf.Abs(myRigidBody.velocity.x) > Mathf.Epsilon;
if (playerHasHorizontalSpeed)
{
transform.localScale = new Vector2(Mathf.Sign(myRigidBody.velocity.x), 1f);
}
}

void OnJump(InputValue value)
{
if (!isAlive) { return; }
if (!myCapsuleCollider.IsTouchingLayers(LayerMask.GetMask("Ground")))
{
return;
}

if (value.isPressed)
{

myRigidBody.velocity += new Vector2(0f, jumpSpeed);
}
}



void GinoDied()
{

if (myCapsuleCollider.IsTouchingLayers(LayerMask.GetMask("Enemy")))
{
isAlive = false;
 
 

