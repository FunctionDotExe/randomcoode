using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public float moveSpeed = 5f;
    public float jumpForce = 5f;
    public KeyCode left;
    public KeyCode right;
    public KeyCode jump;
    public KeyCode crouch;


    private Rigidbody2D rb;

    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        Move();
        Jump();

    }

    void Move()
    {
        Vector3 movement = new Vector3(0, 0, 0);

        if (Input.GetKey(left))
        {
            movement.x -= moveSpeed * Time.deltaTime;
            transform.localScale = new Vector3(-1, 1, 1);
        }
        if (Input.GetKey(right))
        {
            movement.x += moveSpeed * Time.deltaTime;
            transform.localScale = new Vector3(1, 1, 1);
        }

        transform.position += movement;
    }

    void Jump()
    {
        if (Input.GetKeyDown(jump))
        {
            rb.AddForce(new Vector2(0, jumpForce), ForceMode2D.Impulse);
            
        }
    }

  
   
}
