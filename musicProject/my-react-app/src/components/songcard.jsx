

import React from 'react';
const Link = ({ to, children, className }) => <a href={to} className={className}>{children}</a>;


const SongCard = ({ imgSrc, mainText, subText, linkTo }) => {
  return (
    <div className="songcard">
      <img src={imgSrc} className="songimg" alt={mainText} />
      <div className="textblock">
        <p className="maintext">{mainText}</p>
        {}
        <p className="subtext">
          {
            
          }
          <Link to={linkTo}>{subText}</Link> 
        </p>
      </div>
    </div>
  );
};

export default SongCard;